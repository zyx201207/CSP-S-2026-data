#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],n,ans,bao,tot,anss;
char c[1000010];
struct no{
	int x;char y;
}b[1000010],d1[1000010],d2[1000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],ans+=a[i];
	if(ans%2==0){
		ans/=2;
		for(int i=1;i<=n;i++)
			if(ans-a[i]>0) ans-=a[i];
			else{
				bao=i;
				break ;
			}
		for(int i=1;i<=n;i++)
			if(i==bao) b[++tot].x=ans,b[tot].y=c[i],
			b[++tot].x=a[i]-ans,b[tot].y=c[i];
			else b[++tot].x=a[i],b[tot].y=c[i];
		for(int i=1;i<=bao;i++)
			d1[i]=b[i];
		for(int i=bao+1;i<=tot;i++)     
			d2[tot-i+1]=b[i];
		int l=1,r=1,ch1=d1[1].y,ch2=d2[1].y,sum1=d1[1].x,sum2=d2[1].x;
		if(ch1!=ch2) anss+=min(sum1,sum2);
		while(l<=bao&&r<=tot-bao){
			if(sum1<=sum2){
				sum1+=d1[++l].x;ch1=d1[l].y;
				if(ch1!=ch2) {
					anss+=min(abs(sum1-d1[l].x-sum2),d1[l].x);
				}
			}
			else{
				sum2+=d2[++r].x;ch2=d2[r].y;
				if(ch1!=ch2) {
					anss+=min(abs(sum2-d2[r].x-sum1),d2[r].x);
				}
			}
		} 
		cout<<anss;                                 
		return 0;
	}
	else {
		ans=ans/2;
		for(int i=1;i<=n;i++)
			if(ans-a[i]>=0) ans-=a[i];
			else{
				bao=i;a[i]--;
				break ;
			}
//		cout<<bao<<"\n";
		for(int i=1;i<=n;i++)
			if(i==bao) b[++tot].x=ans,b[tot].y=c[i],
			b[++tot].x=a[i]-ans,b[tot].y=c[i];
			else b[++tot].x=a[i],b[tot].y=c[i];
//		for(int i=1;i<=tot;i++)
//			cout<<b[i].x<<" "<<b[i].y<<"\n";
		for(int i=1;i<=bao;i++)
			d1[i]=b[i];//cout<<d1[i].x<<" "<<d1[i].y<<"\n";
		for(int i=bao+1;i<=tot;i++)     
			d2[tot-i+1]=b[i];//cout<<d2[tot-i+1].x<<" "<<d2[tot-i+1].y<<"\n";
		int l=1,r=1,ch1=d1[1].y,ch2=d2[1].y,sum1=d1[1].x,sum2=d2[1].x;
		if(ch1!=ch2) anss+=min(sum1,sum2);//cout<<anss<<"\n";
		while(l<=bao&&r<=tot-bao){
			if(l==bao&&r==tot-bao) break ;
			if(sum1<=sum2){
				sum1+=d1[++l].x;ch1=d1[l].y;
				if(ch1!=ch2) {
					anss+=min(abs(sum1-d1[l].x-sum2),d1[l].x);
//					cout<<min(abs(sum1-sum2),d1[l].x)<<"\n";
				}
			}
			else{
				sum2+=d2[++r].x;ch2=d2[r].y;
				if(ch1!=ch2) {
					anss+=min(abs(sum2-d2[r].x-sum1),d2[r].x);
				}
			}
//			cout<<l<<" "<<r<<"\n";
		} 
		cout<<anss;                                 
		return 0;
	}
}