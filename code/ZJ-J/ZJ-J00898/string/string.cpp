#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=200005;
char ch;
int n,ans,lens,anf,l,r,lenpd2;
struct node{
	int x;char y;
}k[maxn];
//bool a[maxn];
string s;	
//vector<node>pd[maxn];
//vector<node>pd2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>k[i].x>>k[i].y;
//		lens=lens+k[i].x;
//	}
//	for(int i=1;i<=n;i++){
//		ans=ans+k[i].x;
//		if(ans>=lens/2){anf=i;break;}
//	}ans=0;l=1;r=n;
//	while(l<r){
//		if(k[l].x>=k[r].x){
//			pd[l].push_back({k[r].x,k[l].y});
//			pd[r].push_back({k[r].x,k[r].y});
//			k[l].x=k[l].x-k[r].x;
//			r--;
//		}else{
//			pd[r].push_back({k[l].x,k[r].y});
//			pd[l].push_back({k[l].x,k[l].y});
//			k[r].x=k[r].x-k[l].x;
//			l++;
//		}
////		cout<<l<<" "<<r<<"\n";
//	}
//	pd[l].push_back({k[l].x,k[l].y});
////	for(int i=1;i<=n;i++){
////		for(int j=0;j<pd[i].size();j++){
////			cout<<pd[i][j].x<<" "<<pd[i][j].y<<"----";
////		}cout<<"\n";
////	}
//	pd2.push_back({0,'0'});
//	for(int i=1;i<=n;i++){
//		for(int j=(int)(pd[i].size()-1);j>=0;j--){
//			pd2.push_back({pd[i][j].x,pd[i][j].y});
//		}
//	}
//	lenpd2=pd2.size();
////	for(int i=1;i<=lenpd2-1;i++){
////		cout<<pd2[i].x<<" "<<pd2[i].y<<"\n";
////	}
//	for(int i=1;i<=(lenpd2-1)/2;i++){
//		if(pd2[i].y!=pd2[lenpd2-i].y){
//			ans=ans+pd2[i].x;
//		}
//	}cout<<ans;
//	return 0;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>k[i].x>>k[i].y;lens=lens+k[i].x;
		for(int j=1;j<=k[i].x;j++){s=s+k[i].y;}
	}
	for(int i=1;i<=lens/2;i++){
		if(s[i]!=s[lens-i+1]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
