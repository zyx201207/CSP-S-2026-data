#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[500005];
bool f[500005];
int t[500005];
int l[500005];
int sum[500005];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			A=false;
		}
	} 
	if(A){
		int now=a[1],len=1;
		for(int i=2;i<=n;i++){
			if(a[i]==now) len++;
			else{
				l[now]=len;
				now=a[i];
				len=1;
			}
		}
		l[now]=len;
		for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+l[i];
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i-1]*(l[i]&1)+(l[i]+1)/2<<' ';
//			cout<<sum[i-1]<<' '<<l[i]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=false;
		}
		v.clear();
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(v.back()!=a[j]){
					f[v.back()]=false;
					v.pop_back();
				}
				v.pop_back();
				f[a[j]]=true;
			}
			else{
				f[a[j]]=true;
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<(int)v.size();j++){
			t[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
