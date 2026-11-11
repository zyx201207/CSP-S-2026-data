#include<bits/stdc++.h>
using namespace std;
long long n[200000],d[200000],minstep=0,a[100000000],k;
int f(long long x[],long long x_1,long long x_2,long long step,long long i){
	long long num=0;
	if(x[x_2]-x[x_1]<=d[i]&&step+1<=minstep){
		minstep=step+1;
		a[k]=minstep;
		k++;
		return 1;
	}
	if(step+1>=minstep)return 0;
	for(long long i_1=x_1+1;i_1<x_2;i_1++){
		if(x[i_1]-x[x_1]<=d[i]){
			long long b=f(x,i_1,x_2,step+1,i);
			if(b==0)break;
			num+=b;
		}
		else break;
	}
	if(step==0){
		num=0;
		for(int i_1=0;i_1<k;i_1++){
			if(a[i_1]==minstep)num++;
			if(num>2)return 0;
		}
		if(num==2)return 1;
		return 0;
	}
	return num;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int i_1=0;i_1<t;i_1++){
		cin>>n[i_1]>>d[i_1];
		long long x[n[i_1]],num=0;
		for(int i_2=0;i_2<n[i_1];i_2++)cin>>x[i_2];
		for(int i_2=0;i_2<n[i_1]-1;i_2++){
			for(int i_3=i_2+1;i_3<n[i_1];i_3++){
				minstep=(x[i_3]-x[i_2])/d[i_1]+((x[i_3]-x[i_2])%d[i_1]>0);
				if(i_3-i_2<minstep)break;
				if(x[i_2]+d[i_1]>=x[i_3])continue;
				k=0;
				num+=(f(x,i_2,i_3,0,i_1)==1);
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
