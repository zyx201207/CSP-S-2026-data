#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N],cha[N],js[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";
	// cout<<"\n";
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		if(i>=3&&cha[i]!=cha[i-1])
			flag=false;
		js[i]=i+js[i-1];
		js[i-1]*=2;
	}
	js[n]*=2;
	if(flag==true){
		long long sum=m/cha[n];
		long long x=upper_bound(js+1,js+n+1,sum)-js;
		if(n%2==0){
			if(x>=n/2&&sum>=js[n/2-1]+n/2){
				cout<<n;
				return 0;
			}
		}else{
			if(x>n/2)
			{
				cout<<n;
				return 0;
			}
		}
		if(sum>=js[x-1]+x)
		{
			cout<<2*x;
		}else{
			cout<<2*x-1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		cout<<cha[i]<<" ";

	long long ans=-10,num=0;
	long long l=1,r=1,sum=m,lo=0,ro=0;
	for(int i=1;i<=n;i++){
		l=i,r=i+1,sum=m,lo=0,ro=0,num=0;
		while(sum>0&&(l>1||r<=n)){
			if(l>1&&r<=n){
				if(min(lo+cha[l],cha[r]+ro)<=sum){
					if(lo+cha[l]<cha[r]+ro){
						sum-=(lo+cha[l]);
						lo+=cha[l];
						l--;
						num++;
					}else{
						sum-=(cha[r]+ro);
						ro+=cha[r];
						r++;
						num++;
					}
				}
				else break;
			}else if(l>1){
				if(sum>=lo+cha[l]){
					sum-=(lo+cha[l]);
					lo+=cha[l];
					l--;
					num++;
				}else break;
			}else if(sum>=cha[r]+ro){
				sum-=(cha[r]+ro);
				ro+=cha[r];
				r++;
				num++;
			}else break;
		}
		// cout<<i<<" "<<num<<"\n";
		ans=max(ans,num);
	}
	cout<<ans+1;
	return 0;
}