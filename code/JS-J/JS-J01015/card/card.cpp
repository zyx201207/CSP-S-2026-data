#include<bits/stdc++.h>
using namespace std;

int arr[500005];
int cnt[300005];
int store[500005];

queue<int> q;

int main(){
    freopen("card.in","r",stdin);
    freopen("card","w",stdout);

    int n , m;
    cin>>n>>m;

    int maxv = 0;
    for(int i=1 ; i<=n ; ++i){
        cin>>arr[i];
        maxv = max(maxv , arr[i]);
    }

    for(int i=1 ; i<=n; ++i){
        int s = 0;
        for(int j=i ; j<=n ; j++){
            int k = i;
            int pos = 0;

            if(q.empty()){
                q.push(arr[j]);
            }else{
                bool find = false;
                for(int l = k; l < j ; ++l){
                    if(arr[l] == arr[j]){
                        find = true;
                        pos = l;
                    }
                }
                if(find){
                    int p = i;

                    while(!q.empty()){
                        if(q.front() != arr[pos] && p < pos){
                            store[++s] = arr[p];
                            p++;
                        }
                        q.pop();
                    }
                    q.push(arr[j]);
                }else{
                    q.push(arr[j]);
                }
            }
        }
        while(!q.empty()){
            cnt[q.front()]++;
            q.pop();
        }
        for(int c=1 ; c<=s ; ++c){
            cnt[store[c]]++;
        }
    }

    for(int i=1 ; i<=maxv ; ++i){
        cout<<cnt[i]<<' ';
    }
    return 0;
}


