#include<bits/stdc++.h>
using namespace std;

struct p{
	long long a,b,c,d;
}q[1000005];

long long n,m,ai,ma=0,k;

long long er(long long x,long long y){
	long long l=0,r=y;
	while(l<=r){
		long long mid=(l+r)/2;
		if(q[mid].a>x)r=mid-1;
		else if(q[mid].a<x)l=mid+1;
		if(q[mid].a==x)return mid;
	}
	return -1;
}

long long re(long long x,long long y){
	long long l=0,r=x;
	while(l<=r){
		long long mid=(l+r)/2;
		long long t=q[mid].c-q[x].c;
		if(t==m)return mid;
		if(t<m)r=mid-1;
		else l=mid+1;
	}
	return l;
}

bool cmp(p x,p y){
	return x.a<y.a;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ai;
		long long d=er(ai,k-1);
		if(d==-1){
			q[k].a=ai;
			q[k++].b=1;
			if(ma==0)ma=1;
			sort(q,q+k-1,cmp);
		}
		else {
			q[d].b++;
			ma=max(ma,q[d].b);
		}
	}
	if(m==0){
		cout<<ma;
		return 0;
	}
	q[k-1].c=0;
	q[k-1].d=q[k-1].b;
	for(int i=k-2;i>=0;i--){
		q[i].c=q[i+1].c+(q[i+1].a-q[i].a)*q[i].b;
		q[i].d=q[i+1].d+q[i].b;
	}
	for(int i=k-1;i>0;i--){
		long long s=re(i,m);
		long long h=q[s].d-q[i].d;
		if(m-q[s].c-q[s-1].a>=0){
			long long mm=m-q[s].c;
			h+=mm/(q[i].a-q[s-1].a);
		}
		ma=max(ma,h+q[i].b);
	}
	cout<<ma;
	return 0;
}
