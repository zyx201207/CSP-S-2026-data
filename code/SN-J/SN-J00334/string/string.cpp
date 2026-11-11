#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,sum,ci;
int a[200005];
char c[200005];
int b[200005];
unordered_map<int,int> mp;
int idc[30];
pair<int,int> T[30][200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	if(sum<=200005){
		ci=0;
		for(int i=1;i<=n;i++){
			int x=c[i]-'a';
			int h=ci+1,t=ci+a[i];
			ci=ci+a[i];
			for(int j=h;j<=t;j++){
				b[j]=x;
			} 
		}
		int cnt=0;
		for(int i=1;i<=ci;i++){
			if(b[i]!=b[ci+1-i]) cnt++;
		}
		cout<<cnt/2;
		return 0;
	}
	if(sum<=100000000){
		ci=0;
		for(int i=1;i<=n;i++){
			int x=c[i]-'a';
			int h=ci+1,t=ci+a[i];
			ci=ci+a[i];
			for(int j=h;j<=t;j++){
				mp[j]=x;
			} 
		}
		int cnt=0;
		for(int i=1;i<=ci;i++){
			if(mp[i]!=mp[ci+1-i]) cnt++;
		}
		cout<<cnt/2;
		return 0;
	}
	if(n<=2000){
		ci=0;
		for(int i=1;i<=n;i++){
			int x=c[i]-'a';
			int h=ci+1,t=ci+a[i];
			ci=ci+a[i];
			int fl=0;
			for(int j=1;j<=idc[x];j++){
				if(T[x][j].second==h-1){
					T[x][j].second=t;
					fl=1;
					break;
				}
			}
			if(fl==0){
				idc[x]++;
				T[x][idc[x]].first=h;
				T[x][idc[x]].second=t;
			}
	//		for(int j=1;j<=idc[x];j++){
	//			cout<<T[x][j].first<<" "<<T[x][j].second<<endl;
	//		}
		}
		int cnt=0;
		for(int i=0;i<26;i++){
			for(int j=1;j<=idc[i];j++){
				int h=T[i][j].first,t=T[i][j].second;
				h=ci+1-h,t=ci+1-t;
				swap(h,t);
				int xc=0;
				for(int k=1;k<=idc[i];k++){
	//				if(k==j) continue;
					if(T[i][k].first<=h&&T[i][k].second>=h){
						xc=xc+min(t,T[i][k].second)-h+1;
					}
					else if(T[i][k].first<=t&&T[i][k].second>=t){
						xc=xc+t-max(h,T[i][k].first)+1;
					}
					else if(T[i][k].first>=h&&T[i][k].second<=t){
						xc=xc+T[i][k].second-T[i][k].first+1;
					}
				}
				cnt+=xc;
			}
		}
		cout<<(ci-cnt)/2;
		return 0;
	}
	return 0; 
}
