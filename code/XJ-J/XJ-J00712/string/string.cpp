#include<bits/stdc++.h>
using namespace std;
string a;
char b[200005],zuo2[200005],you2[200005];
int lo[200005],zuo1[200005],you1[200005];
int n;
long long sumn,ans;
int main(){
	freopen("stding.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lo[i];
		cin>>b[i];
		sumn+=lo[i];
	}
	long long h=sumn/2;
	int j=1;
	long long he=0;
	for(int i=1;i<=n;i++){
		if(lo[i]+he<h){
			he+=lo[i];
			zuo1[j]=lo[i];
			zuo2[j]=b[i];
			j++;
		}
		if(lo[i]+he>=h){
			zuo1[j]=h-he;
			zuo2[j]=b[i];
			break;
		}
	}
	int j1=j;
	j=1;
	he=0;
	for(int i=n;i>=1;i--){
		if(lo[i]+he<h){
			he+=lo[i];
			you1[j]=lo[i];
			you2[j]=b[i];
			j++;
		}
		if(lo[i]+he>=h){
			zuo1[j]=h-he;
			zuo2[j]=b[i];
			break;
		}
	}
	for(int i=1;i<=max(j1,j);i++){
		if(zuo2[i]!=you2[i]){
			ans+=min(zuo1[i],you1[i]);
		}
		if(zuo1[i]!=you1[i]){
			ans+=abs(zuo1[i]-you1[i]);
		}
	}
	cout<<ans;
	return 0;
}