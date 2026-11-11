#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int arr[N];
vector<int> poker;
bool flag[N];
int ans;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n==1){
        if(arr[1]==1){
            cout<<1<<" "<<0;
        }else{
            cout<<0<<" "<<1;
        }
    }else if(n==2){
        if(arr[1]==arr[2]){
            if(arr[2]==arr[1]){
                if(arr[2]==1){
                    cout<<1<<" "<<0;
                }else{
                    cout<<0<<" "<<1;
                }
            }else{
                cout<<1<<" "<<1;
            }
        }
    }else if(n==3){
        if(arr[1]==arr[2]&&arr[2]!=arr[3]||arr[1]!=arr[2]&&arr[2]==arr[3]){
            cout<<1<<" "<<1;
        }else if(arr[1]!=arr[2]&&arr[2]!=arr[3]){
            if(arr[3]==1){
                cout<<2<<" "<<1;
            }else if(arr[3]==2){
                cout<<1<<" "<<2;
            }
        }else{
            cout<<0<<" "<<0;
        }

    }else if(n==4){
        if(arr[1]==arr[2]&&arr[2]==arr[3]&&arr[3]==arr[4]){
            cout<<0<<" "<<0;
        }else if(arr[1]!=arr[2]&&arr[2]==arr[3]&&arr[3]==arr[4]||arr[1]==arr[2]&&arr[2]!=arr[3]&&arr[3]==arr[4]||arr[1]==arr[2]&&arr[2]==arr[3]&&arr[3]!=arr[4]){
            if(arr[1]==1){
                cout<<1<<" "<<0;
            }else{
                cout<<0<<" "<<1;
            }
        }else if(arr[1]!=arr[2]&&arr[2]!=arr[3]&&arr[3]==arr[4]||arr[1]==arr[2]&&arr[2]!=arr[3]&&arr[3]!=arr[4]){
            cout<<1<<" "<<1;
        }else if(arr[1]!=arr[2]&&arr[2]==arr[3]&&arr[3]!=arr[4]){
            if(arr[1]==1){
                cout<<2<<" "<<0;
            }else{
                cout<<0<<" "<<2;
            }
        }
    }




    return 0;

}

