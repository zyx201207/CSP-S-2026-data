#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000000],xl[5000],start[100000+5],end[100000+5],ig[50000],t[50000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>xl[i];
		for(int j=xl[i-1]+1;j<=xl[i]+xl[i-1];j++) cin>>ig[j]>>t[j];
	}
	for(int i=1;i<=q;i++)
		cin>>start[i]>>end[i];
	for(int i=1;i<=q;i++){
		int s=0;
		s+=w[start[i]];
		for(int j=xl[start[i]-1]+1;j<=xl[start[i]]+xl[start[i]-1];j++){
			if(ig[j]==end[i]){
				s=s+t[start[i]]+t[j]+w[end[i]];
				cout<<s<<endl;
				break;
			}
		} 
	}
	return 0;
}
