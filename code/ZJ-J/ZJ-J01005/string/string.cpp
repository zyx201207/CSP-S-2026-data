#include<bits/stdc++.h>
using namespace std;
int n,pos1,pos2;char c[200005];long long a[200005],sumn,summ,ans;
struct Node{int val;char nc;}s1[200005],s2[200005];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i]>>c[i];sumn+=a[i];}int p=sumn;sumn/=2;
	for(int i=1;i<=n;i++){
		summ+=a[i];
		if(summ>=sumn){pos1=i;pos2=a[i]-summ+sumn;break;}
	}for(int i=1;i<=pos1;i++){
		s1[i].nc=c[i];
		if(i!=pos1)s1[i].val=a[i];
		else s1[i].val=pos2;
	}for(int i=n;i>=pos1;i--){
		s2[n-i+1].nc=c[i];
		if(i!=pos1)s2[n-i+1].val=a[i];
		else if(p&1)s2[n-i+1].val=a[i]-pos2-1;
		else s2[n-i+1].val=a[i]-pos2;
	}int p1=1,p2=1,sum1=s1[1].val,sum2=s2[1].val;
	while(p1<=pos1&&p2<=n-pos1+1){
		if(sum1>=sum2){
			if(s1[p1].nc!=s2[p2].nc)ans+=sum2;
			sum1-=sum2;sum2=s2[++p2].val;
		}else{
			if(s1[p1].nc!=s2[p2].nc)ans+=sum1;
			sum2-=sum1;sum1=s1[++p1].val;
		}
	}cout<<ans;
	return 0;
}
