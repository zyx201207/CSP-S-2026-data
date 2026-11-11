#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int List[N],List2[N],n,m,temp;
bool find=false;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>List[i];
    }
    int left=0,right=n-1;
    for(int a=29;a>=0;a--){
        for(int i=left;i<right;i++){
            if((List[i]>>(a))%2==1){
                temp=List[i];
                List[i]=List[left];
                List[left]=temp;
                left++;
            }
        }
        if(left>=m){
            right=left;
        }
        left=0;
    }
    int ans=List[0];
    for(int i=1;i<m;i++){
        ans=ans&List[i];
    }cout<<ans;
    return 0;
}
