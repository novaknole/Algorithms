#include <iostream>
#include <string.h> 
using namespace std;

bool bpGraph[2000][2000];
int matchR[2000];


bool bpm(int u, bool seen[], int matchR[],int sockets, int devices, int socketDevices[]) { 
    for (int v = 0; v < devices; v++) { 
        if (bpGraph[u][v] && !seen[v]) { 
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR,sockets,devices,socketDevices)) { 
                matchR[v] = u;
                socketDevices[u] = v;
                return true; 
            } 
        } 
    } 
    return false; 
} 
  
// sockets applications M
// devices jobs N
int maxBPM(int sockets,int devices){
    int matchR[devices]; 
    int socketDevices[sockets];
    memset(matchR, -1, sizeof(matchR));  
    memset(socketDevices, -1, sizeof(socketDevices));

    int result = 0;  
    for (int u = 0; u < sockets; u++) { 
        bool seen[devices]; 
        memset(seen, 0, sizeof(seen)); 
        if (bpm(u, seen, matchR,sockets,devices,socketDevices)) 
            result++; 
    }

    int socketsInterested[sockets];
    memset(socketsInterested, 0, sizeof(socketsInterested));

    for(int i=0;i<sockets;i++){
        for(int j=0;j<devices;j++){
            bool ifInterested = bpGraph[i][j];
            if(ifInterested && matchR[j] == -1){
                socketsInterested[i]++;
                if(socketsInterested[i] > 1) return result+2;
            }
        }
    }
    for(int i=0;i<sockets-1;i++){
        for(int j=i+1;j<sockets;j++){
            if(socketsInterested[i] > 0 && socketsInterested[j] > 0){
                int socketOneDevice = socketDevices[i];
                int socketTwoDevice = socketDevices[j];
                
                if(bpGraph[i][socketTwoDevice] || bpGraph[j][socketOneDevice]) return result+2;
            }
        }
    }

    int maximum =0;
    for(int i=0;i<sockets;i++){
        if(socketsInterested[i]>maximum) maximum = socketsInterested[i];
    }

    if(maximum > 2) return result+2;
    else return result+maximum;






} 


int main(){
    int sockets;
    int devices;
    int connections;
    cin>>sockets; cin>>devices;cin>>connections;
    for(int i=0;i<sockets;i++){
        for(int j=0;j<devices;j++){
            bpGraph[i][j] = 0;
        }
    }

    for(int i=0;i<connections;i++){
        int x;int y;
        cin>>x; cin>>y;
        x--; y--;
        bpGraph[x][y] = 1;
    }

    cout<<maxBPM(sockets,devices)<<endl;


}