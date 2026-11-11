#include<bits/stdc++.h>
using namespace std;
long long a[500500],a2[500500],b[500500];
long long c[500500],a3[500500];
long long n,m,f=1,tp,j=0;
bool cmp(long long q,long long w){
	return q<w;
}//第一题就这么难 想干嘛
//75pts(?
//晚安 1217king 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	//Oct31==Dec25?
	cin>>n>>m;
	long long m2=m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);b[0]=0;a2[0]=a[0];
	for(int i=1;i<n;i++){
		if(a[i]==a2[j]){
			f++;
		}
		else{
			a3[j]=f;a2[j+1]=a[i];j++;f=1;
		}
	}
	a3[j]++;
	j++;f=1;
	tp=a2[1]-a2[0];
	for(int i=1;i<j;i++){
		b[i]=a2[i]-a2[i-1];
		if(tp!=b[i]) f=0;
	}
	//------------------------------
	if(f==0){
		
	long long ans=0,mans=0;
	for(int i=j-1,k=1;i>=0;i--){
		k=1;
		m=m2;
		ans=a3[i];
		while(m>=0&&i-k>=0){
			m-=(a2[i]-a2[i-k])*a3[i-k];ans+=a3[i-k];
			
			k++;
		}
		if(i-k<0 && m>=0){
			mans=max(mans,ans);
		}
		if(m<0){
			k--;ans-=a3[i-k];
			m+=(a2[i]-a2[i-k])*a3[i-k];
			while(m>=0){
				m-=(a2[i]-a2[i-k]);ans++;
			}
			ans--;
			mans=max(mans,ans);
		}
	}
	cout<<mans;return 0;
	}//o n^2 
	//------------------------------
	if(f==1){
		if(tp<=0){cout<<n;return 0;}
		if(tp>0){
			for(int i=1;i<=n;i++){
				if(i*(i-1)/2*tp>m){
					cout<<i-1;
					return 0;
				}
			}
			cout<<n;
			return 0;
		}
	}//13-18
	return 0;
}
