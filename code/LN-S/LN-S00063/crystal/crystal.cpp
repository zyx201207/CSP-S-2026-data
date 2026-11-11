#include<bits/stdc++.h>
using namespace std;
const int N=5e+5;
long long m,m1;
int a[N],b[N];
int num=1,k=1,s=0,ans=0;
void d(int x){
	if(a[num]==a[num+1]&&num<n){
		s+=1;
	}
	if(k<n){
		num=k;
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
		m=m1;
		s=0;
		k++;
		d(a[k]);
	}
	while(m>0){
		if(a[num]>a[num+1]){
			a[num]++;
			m--;
		}else if(a[num]>a[num-1]&&num<n&&a[num]==a[num+1]){
			num--;
			a[num]++;
			m--;
		}else{
			num++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]||(a[i]==a[i-1]&&i>1)) s++;
    }
	if(s>ans) ans=s;
}
int main(){
    ios::sync_with_stdio(False);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    m1=m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
    }
    d(a[0]);
    cout<<ans;
    return 0;
}
