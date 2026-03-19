//螺旋遍历二维数组
//设置四个变量分别记录二维数组的上下左右

//c语言版
int* spiralArray(int** array, int arraySize, int* arrayColSize, int* returnSize) {
    if(arraySize == 0 || arrayColSize[0] == 0){
        *returnSize = 0;
        return NULL;
    }
    int rows = arraySize,cols = arrayColSize[0];
    int total = rows * cols;
    int *res = (int *)malloc(sizeof(int) * total);
    *returnSize = 0;
    int l = 0,r = cols -1,t = 0,b = rows-1;
    while(true){
        for(int i = l;i<=r;i++) res[(*returnSize)++] = array[t][i];
        if(++t > b) break;
        for(int i = t;i<=b;i++) res[(*returnSize)++] = array[i][r];
        if(l > --r) break;
        for(int i = r;i>=l;i--) res[(*returnSize)++] = array[b][i];
        if(t > --b) break;
        for(int i = b;i>=t;i--) res[(*returnSize)++] = array[i][l];
        if(++l > r) break;
    }
    return res;
}

//c++版
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if(array.empty()) return {};//不能写return NULL
        int l = 0,r = array[0].size() - 1,t = 0,b = array.size() - 1;
        vector<int> res;
        while(true){
            for(int i = l;i<=r;i++) res.push_back(array[t][i]);//向量可以动态添加元素
            if(++t > b) break;
            for(int i = t;i<=b;i++) res.push_back(array[i][r]);
            if(l > --r) break;
            for(int i = r;i>=l;i--) res.push_back(array[b][i]);
            if(t > --b) break;
            for(int i = b;i>=t;i--) res.push_back(array[i][l]);
            if(++l > r) break;
        } 
        return res;
    }
};