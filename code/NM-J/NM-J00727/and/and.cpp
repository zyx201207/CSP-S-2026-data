#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=0;
    int m=0;
    cin >>n >>m;
    int s[n]={0};
    for(int i = 0;i<n ;i++){
        cin >>s[i];
    }
    int max = 0;
    for(int i = 0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
                int xx = 0;
                if(s[i]<s[j]){
                    xx = s[i];
                }else{
                xx=s[j];
        }
            //int xx=s[i]&&s[j];
            //cout <<xx <<endl;
            if(xx>max){
                max=xx;
                xx = 0;
            }
        }
    }cout<<max;
    return 0;
}
