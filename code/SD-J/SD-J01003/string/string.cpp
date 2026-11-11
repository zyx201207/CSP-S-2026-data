#include<iostream>
using namespace std;
const int N=201000;
struct lett{
	long long p;
	char le;
}a[N],l[N],r[N];
long long n;
unsigned long long tot=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long f=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i].p>>a[i].le;
		tot+=a[i].p;
	}
	long long haltot=tot/2;
	bool yu=false;
	int flagl=1,flaga=1;
	while(!yu){
		if(haltot>=a[flaga].p){
			haltot-=a[flaga].p;
			l[flagl].p=a[flaga].p;
			l[flagl].le=a[flaga].le;
		}else{
			l[flagl].p=haltot;
			l[flagl].le=a[flaga].le;
			yu=true;
			break;
		}
		flagl++;
		flaga++;
	}
	long long flagr=1;
	if(yu){
		if(a[flaga-1].p-l[flagl-1].p>0){
			r[1].le=a[flaga-1].le;
			r[1].p=a[flaga-1].p-l[flagl-1].p;
			flagr++;
		}
		for(long long i=flaga;i<=n;i++){
			r[flagr].p=a[i].p;
			r[flagr].le=a[i].le;
			flagr++;
		}
	}
	flagr--;
	flagl=1;
	haltot=tot/2;
	long long ans=0;
	while(haltot){
		if(l[flagl].le!=r[flagr].le){
			if(l[flagl].p<r[flagr].p){
				ans+=l[flagl].p;
				r[flagr].p-=l[flagl].p;
				haltot-=l[flagl].p;
				flagl++;
			}else if(l[flagl].p>r[flagr].p){
				ans+=r[flagr].p;
				l[flagl].p-=r[flagr].p;
				haltot-=r[flagr].p;
				flagr--;
			}else{
				ans+=l[flagl].p;
				haltot-=l[flagl].p;
				flagl++;
				flagr--;
			}
		}
		else{
			if(l[flagl].p<r[flagr].p){
				r[flagr].p-=l[flagl].p;
				haltot-=l[flagl].p;
				flagl++;
			}else if(l[flagl].p>r[flagr].p){
				l[flagl].p-=r[flagr].p;
				haltot-=r[flagr].p;
				flagr--;
			}else{
				haltot-=l[flagl].p;
				flagl++;
				flagr--;
			}
		}
	}
	cout<<ans;
	return 0;
}
