#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],ans[M];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        vector<int> v;
        v.push_back(a[i]);
        for(int j=i+1;j<=n;j++){
            for(int k=0;k<v.size();k++){
                if(v[k]==a[j]){
                    while(v.size()>k){
                        v.pop_back();
                    }
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int x: v){
            ans[x]++;
        }
	}
	for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}

