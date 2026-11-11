#include<bits/stdc++.h>
using namespace std;
int s[100001],t[100001][1],ns[100001];
string a,b;
int d,c,n,m,cnt=0,ans=0,ans2=0,h,o,l,ll;
int check(int op,int iu){
	return op>=iu;
}
int an(int k,int p){
	if(k==p){
		return k;
	}
	ans=0;
	cnt=0;
	while(k>0){
		d=k%2;
		k/=2;
		a[cnt]=d+'0';
		cnt++;
	}
	h=cnt;
	cnt=0;
	while(p>0){
		d=p%2;
		p/=2;
		b[cnt]=d+'0';
		cnt++;
	}
	o=cnt;
	cnt=0;
	if(h>=o){
		cnt=o;
	}
	else{
		cnt=h;
	}
	for(int i=cnt-1;i>=0;i--){
		if(a[i]==b[i]&&a[i]=='1'){
			d=1;
			c=i;
			while(c>0){
				d*=2;
				c--;
			}
			ans+=d;
		}
	}
	return ans;
}
int bn(int g){
	ans2=0;
	while(g>0){
		if(g%2==1){
			ans2++;
		}
		g/=2;
	}
	return ans2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		t[i][0]=bn(s[i]);
		t[i][1]=i;
	}
	if(m==1){
		sort(s+1,s+n+1,check);
		cout<<s[1];
		return 0;
	}
	if(n>=2000){
		sort(s+1,s+n+1,check);
		cout<<s[2];
		return 0;
	}
	sort(t[0]+1,t[0]+n+1,check);
	int f,w;
	if(n<=10){
		f=n;
	}
	if(10<n&&20>=n){
		f=n/2;
	}
	if(20<n&&60>=n){
		f=n/7;
	}
	if(60<n&&120>=n){
		f=n/12;
	}
	if(120<n&&300>=n){
		f=n/40;
	}
	if(300<n&&600>=n){
		f=n/80;
	}
	if(600<n&&1200>=n){
		f=n/250;
	}
	
	else{
		f=n/500;
	}
	for(int i=1;i<=f;i++){
		for(int j=1;j<m;j++){
			w=t[j][1];
			if(j!=1){
				l=ns[i];
				ns[i]=an(l,s[w+1]);	
			}
			else{
				l=s[w];
				ll=s[w+1];
				ns[i]=an(l,ll);
			}
		}
	}
	sort(ns+1,ns+f+1,check);
	cout<<ns[1];
}
