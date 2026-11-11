#include<bits/stdc++.h>
using namespace std;
int a[500005];
int f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool is=1;
	int ls=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		is&=(a[i-1]<=a[i]);
	}
	if(is){
        for(int i=1;i<=n;i++){
            int ls[m+2]={0};
            for(int j=i;j<=n;j++){
                ls[a[j]]=1;
            }
            for(int j=1;j<=m;j++){
                f[j]+=ls[j];
            }
        }
		for(int i=1;i<=m;i++){
			cout<<f[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int j=i;j<=n;j++){
			int out=a[j];
			int id=-1;
			for(int k=(int)v.size()-1;k>=0;k--){
				if(v[k]==out){
					id=k;
					break;
				}
			}
			if(id==-1){
				v.push_back(a[j]);
			}
			for(int k=(int)v.size()-1;k>id;k--){
				v.pop_back();
			}
		}
		for(int x:v){
			f[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
