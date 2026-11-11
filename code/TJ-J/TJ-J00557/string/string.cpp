#include<bits/stdc++.h>
using namespace std;
long long n,mid,zk=1,yk=1,ymid,sumn=0;
long long sl[200010];
long long qzh[200010];
long long zsl[200010];
char zzf[200010];
long long ysl[200010]; 
char yzf[200010];
char zf[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int a=1;a<=n;++a){
		cin>>sl[a]>>zf[a];
	}
	for(int a=1;a<=n;++a){
		qzh[a]=qzh[a-1]+sl[a];
	}
	mid=qzh[n]/2;
	if(qzh[n]%2==1)ymid=mid+1;
	else ymid=mid;
	for(int a=1;a<=n;++a){
		if(qzh[a]>=mid){
			zsl[zk]=mid;
			zzf[zk]=zf[a];
			break;
		}
		zzf[zk]=zf[a];
		zsl[zk]=qzh[a];
		++zk;
	}
	for(int a=n;a>=1;--a){
		if(qzh[a-1]==ymid){
			yzf[yk]=zf[a];
			ysl[yk]=qzh[a];
			break;
		}
		if(qzh[a-1]<ymid){
			yzf[yk]=zf[a];
			ysl[yk]=qzh[a];
			break;
		}
		yzf[yk]=zf[a];
		ysl[yk]=qzh[a];
		++yk;
	}
	for(int a=1;a<yk;++a){
		ysl[a]=ysl[a]-ysl[a+1];
	}
	ysl[yk]=ysl[yk]-ymid;
	for(int a=1;a<=yk;++a){
		ysl[a]+=ysl[a-1];
	}
	for(int a=1,b=1;a<=zk&&b<=yk;){
		if(zsl[a]>=ysl[b]){
			if(zsl[a-1]+1>=ysl[b-1]+1){
				if(zzf[a]!=yzf[b]){
					sumn+=ysl[b]-zsl[a-1];
				}
				if(zsl[a]==ysl[b]){
					++a;
					++b;
				}else{
					++b;
				}
			}else{
				if(zzf[a]!=yzf[b]){
					sumn+=ysl[b]-ysl[b-1];
				}
				if(zsl[a]==ysl[b]){
					++a;
					++b;
				}else{
					++b;
				}
			}
		}else{
			if(zsl[a-1]+1<=ysl[b-1]+1){
				if(zzf[a]!=yzf[b]){
					sumn+=zsl[a]-ysl[b-1];
				}
				++a;
			}else{
				if(zzf[a]!=yzf[b]){
					sumn+=zsl[a]-zsl[a-1];
				}
				++a;
			}
		}
	}
	cout<<sumn;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/ 
