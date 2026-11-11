#include<bits/stdc++.h>/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/
#define ll long long
using namespace std;
int f[2000009],sum=0,count1=0,df[2000009],ch=0;
struct n{
	int a,b,c;
};
n e[2000009];
getf(int a){
	if(f[a]==a)return a;
	f[a]=getf(f[a]);
	return f[a];
}
bcj(int a,int b){
	int t1=getf(a);
	int t2=getf(b);
	if(t1!=t2){
		f[t1]=f[t2];
		return 1;
	}
	return 0;
}
bool cmp(n a,n b){
	return a.c<b.c;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,m,b,r,c,sum=0;
	cin>>b>>r;
	for(int i=1;i<=r;i++){
		cin>>n>>c;
		m=n-1;
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[i].a>>e[i].b;
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(bcj(e[i].a,e[i].b)){
				count1++;
			}
			if(count1==n-1) {
				for(int i=1;i<=n;i++){
					df[f[i]]++;
				}
				for(int i=1;i<=n;i++){
					if(df[i]!=0){
						ch++;
					}
				}
			}
		}
		
		cout<<ch;
		ch=0;	
	}
	return 0;
}
