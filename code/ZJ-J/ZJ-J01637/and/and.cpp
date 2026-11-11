#include<bits/stdc++.h>
using namespace std;
bool get(long long a,int t){
	return (a>>t)&1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<long long> t(n);
	vector<bool> flag(n),last(n);
	for(int i=0;i<n;i++){
		cin>>t[i];
		last[i]=flag[i]=1;
	}
	int size=n,lastsize=n;
	for(int i=32;i>=0;i--){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(flag[j]==1&&get(t[j],i)==0)flag[j]=0,size--;
		}
		if(size==m)break;
		else if(size<m){
			size=lastsize;
			flag=last;
		}else{
			lastsize=size;
			last=flag;
		}
	}
	long long ans=-1;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(flag[i]==1&&cnt<=m){
			if(ans==-1)ans=t[i];
			else ans&=t[i];
			cnt++;
		}
		if(cnt>m)break;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
