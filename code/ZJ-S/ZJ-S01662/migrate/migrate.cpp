#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,T;
long long a[N];
vector<int> adj[N];
vector<int> cnt[N];
int find(int x,int n){
	int l=0;
	int r=n+10;
	int ans=0;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<x)l=mid+1;
		else ans=mid,r=mid;
	}
	return ans;
}
int main(){
	cin>>c>>T;
	while(T--){
		int n,d;
		long long sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int l=a[i]-d;
			int r=a[i]+d;
			int s,t;
			for(int j=i;j>=0;j--){
				if(a[j]<l){
					s=j+1;
					break;
				}
			}
			for(int j=i;j<=n;j++){
				if(a[j]>r){
					t=j-1;
					break;
				}
			}
			cnt[s].push_back(t);
		}
		for(int i=1;i<=n;i++){
			set<int> st;
			int l=cnt[i].size();
			for(int j=0;j<l;j++){
				st.insert(cnt[i][j]);
				cout<<cnt[i][j]<<" ";
			}
			cout<<"\n";
			sum+=l-st.size();
		}
		for(int i=1;i<=n;i++){
			int x,y;
			x=find(a[cnt[i][cnt[i].size()-2]]+d,n)-1;
			y=find(a[cnt[i][cnt[i].size()-1]]+d,n)-1;
			sum+=y-x;
			while(y<=n){
				x=find(a[x]+d,n)-1;
				y=find(a[y]+d,n)-1;
				if(y>n)break;
				sum+=y-x;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
