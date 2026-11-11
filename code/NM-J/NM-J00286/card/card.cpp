#include<bits/stdc++.h>
using namespace std;

int hfind(vector<int>ls,int s,int siz){
    for(int i = 0;i < siz;i++){
        if(ls[i] == s){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    int n,m,tmp,ans,t=0,tmp1;
    vector<int> ls;
    vector<int> desk;
    vector<int> f;
    cin >> n >> m;
    for(int i = 0 ;i < n;i++){
        cin >> tmp;
        ls.push_back(tmp);
        tmp1 = hfind(desk,tmp,t);
        if(tmp1 == -1){
            desk.push_back(tmp);
            t++;
            if(tmp == m || hfind(desk,m,t)) {
                f.push_back(i+1);
                ans++;
            }
        else{

            while(1){
                desk.pop_back();
                t--;
                if(tmp != desk[tmp1]) break;
            }
        }
    	}
    }
    freopen("card.out","w",stdout);
    for(int k = 0;k < ans;k++){
        cout << f[k] << " ";
    }
    cout << endl; 
    return 0;
}
