#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,zzm[N],fzm[N];
long long zs[N],fs[N];
long long ans,zl;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i){
		long long x;
		int as;
		char a;
		cin>>x>>a;
		as=a+1-'a';
		zzm[i]=as;
		fzm[n-i+1]=as;
		zs[i]=x;
		fs[n-i+1]=x;
		zl+=x;
	}
	long long tot=0;
	long long zsy=0,fsy=0;
	int zi=0,fi=0;
	while(tot<zl/2){
		if(zsy==0) zsy=zsy+zs[++zi];
		if(fsy==0) fsy=fsy+fs[++fi];
		if(zsy>=fsy){
			long long fyl=fsy;
			zsy-=fyl;
			fsy=0;
			tot+=fyl;
			if(zzm[zi]!=fzm[fi]){
				ans+=fyl;
			}
		}
		else if(fsy>zsy){
			long long fyl=zsy;
			fsy-=fyl;
			zsy=0;
			tot+=fyl;
			if(zzm[zi]!=fzm[fi]) ans+=fyl;
		}
	}
	cout<<ans;
	return 0;
}

