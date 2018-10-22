<?php
class Node {
    public $value;
    public $left;
    public $right;
    public $height;
    public $size;
    function __construct($data, Node $left = null, Node $right = null, $height = 1, $size = 1) {
        $this->data = $data;
        $this->left = $left;
        $this->right = $right;
        $this->height = $height;
        $this->size = $size;
    }
}
function node($data, Node $left = null, Node $right = null, $height = 1, $size = 1) {
    return new Node($data, $left, $right, $height, $size);
}
    function leftRotate(Node $root){
        $newRoot = $root->right;
        $root->right = $root->right->left;
        $newRoot->left = $root;
        $root->height = setHeight($root);
        $root->size = setSize($root);
        $newRoot->height = setHeight($newRoot);
        $newRoot->size = setSize($newRoot);
        return $newRoot;
    }
    
    function rightRotate(Node $root){
        $newRoot = $root->left;
        $root->left = $root->left->right;
        $newRoot->right = $root;
        $root->height = setHeight($root);
        $root->size = setSize($root);
        $newRoot->height = setHeight($newRoot);
        $newRoot->size = setSize($newRoot);
        return $newRoot;
    }
    function setHeight(Node $root = null){
        if (is_null($root)) {
            return 0;
        }
        return 1 + max(($root->left != null ? $root->left->height : 0), ($root->right != null ? $root->right->height : 0));
    }
    
    function height(Node $root = null){
        if (is_null($root)) {
            return 0;
        }else {
            return $root->height;
        }
    }
    
    function setSize(Node $root = null){
        if (is_null($root)) {
            return 0;
        }
        return 1 + max(($root->left != null ? $root->left->size : 0), ($root->right != null ? $root->right->size : 0));
    }
    function addToArray($value, $array = []){
        array_push( $array, $value);
        return $array;
    }
    function insert(Node $root = null, int $data, &$count, int $pos, int $val){
        if (is_null($root)) {
            $count[$pos] = $val;
            $node = node($data);
            return $node;
        }
        if($root->data < $data){
            $root->right = insert($root->right, $data, $count, $pos, $val);
        }
        else{
           $val++;
            if($root->right != null){
                $val += $root->right->size;
            }
            
            $root->left = insert($root->left, $data, $count, $pos, $val);
        }
        if(height($root->left) - height($root->right) > 1){
            if(height($root->left->left) >= height($root->left->right)){
                $root = rightRotate($root);
        }else{
                $root->left = leftRotate($root->left);
                $root = rightRotate($root);
            }
        }else if(height($root->right) - height($root->left) > 1){
            if(height($root->right->right) >= height($root->right->left)){
                $root = leftRotate($root);
            }else{
                $root->right = rightRotate($root->right);
                $root = leftRotate($root);
            }
        }
        else{
            $root->height = setHeight($root);
            $root->size = setSize($root);
        }
        return $root;
    }
    
    function counter($input = []){
        $count = [];
        $root = null;
        for($i = 0; $i < count($input); $i++){
            $root = insert($root, $input[$i], $count, $i, 0);
        }
        return $count;
    }
    
        //$input =   [2674,365751,986347,110564,949107,628932,60432];
        $input =  [0,5,20,3,18,15,2];
        $input = counter($input);
        for($i=0;$i<sizeof($input);$i++){
            echo 7 - $input[$i]."\n";
        }
        // print_r($count);
        // 10
        // 10
        // 10
        // 8
        // 9
        // 8
        // 5
        // 7
        // 4
        // 7