#include<bits/stdc++.h>
using namespace std;
int ii=1,it=0;
struct stru{
	long long num;
	int time=0,rp;
}zzz[500001];
struct op{
	long long num;
	int rp;
}zo[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long mm;
	long long a[500001];
	cin>>n>>mm;
	int ss=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ss+=a[i];
	}
	sort(a+1,a+n+1);
	long long pg=ss/n;
	int l=1,r=n,pgi;
	while(l<=r){
		long long mid=a[(l+r)/2];
		if(pg==mid){
			pgi=(l+r)/2;
			break;
		}else if(pg<mid){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	long long zw1=a[n/2+1];
	long long zw2_1=a[n/2];
	long long zw2_2=a[n/2+1];
	for(int i=1;i<=n;i++){
		if(i==1||a[i-1]<a[i]){
			ii++;
			zzz[ii].rp=i;
			zzz[ii].num=a[i];
			zzz[ii].time++;
		}else{
			zzz[ii].rp=i;
			zzz[ii].time++;
		}
	}
	int mt=0;
	for(int i=1;i<=ii;i++){
		if(zzz[i].time>mt){
			it=1;
			zo[it].num=zzz[i].num;
			zo[it].rp=zzz[i].rp;
			mt=zzz[i].num;
		}else if(zzz[i].time==mt){
			it++;
			zo[it].num=zzz[i].num;
			zo[it].rp=zzz[i].rp;
		}
	}
	int syg1=0,m=mm;
	for(int i=pgi;i>=1;i--){
		if(m>=pg-a[i]){
			m-=pg-a[i];
			syg1++;
		}else{
			break;
		}
	}
	int syg2_1=0,syg2_2=0;
	m=mm;
	if(n%2){
		for(int i=n/2+1;i>=1;i--){
			if(m>=zw1-a[i]){
				m-=zw1-a[i];
				syg2_1++;
			}else{
				break;
			}
		}
	}else{
		for(int i=n/2;i>=1;i--){
			if(m>=zw2_1-a[i]){
				m-=zw2_1-a[i];
				syg2_1++;
			}else{
				break;
			}
		}
		m=mm;
		for(int i=n/2+1;i>=1;i--){
			if(m>=zw2_2-a[i]){
				m-=zw2_2-a[i];
				syg2_2++;
			}else{
				break;
			}
		}
	}
	int syg3=0;
	m=mm;
	for(int j=1;j<=it;j++){
		int syglt=0;
		for(int i=zo[j].rp;i>=1;i--){
			if(m>=zo[j].num-a[i]){
				m-=zo[j].num-a[i];
				syglt++;
			}else{
				break;
			}
		}
		if(syglt>syg3) syg3=syglt;
	}
	cout<<max(max(syg1,syg3),max(syg2_1,syg2_2));
	return 0;
}

