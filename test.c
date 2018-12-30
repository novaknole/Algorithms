int main(){
    int array[5];
    
    array[0]=1;
    array[1]=3;
    array[2]=4;
    array[3]=128;
    array[4]=5;
    
    ((short *)array)[7] = 2;

    for(int i=0;i<5;i++){
        printf("%d\n", array[i]);
    }
}