#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+13;
ll a[N],c[N];
ll sum[N];
int n;
ll m;
bool flag;
set<int>ms; 
int main(){
	
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	ll t;
	sort(a+1,a+n+1);
	sum[1]=a[1];
		for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		t=c[i];
		ms.insert(t);
	}
	//A 
	if(ms.size()==1){
		if(t==1){
	       if(n%2==0){
	       	if(m>=(n/2)){
	       		cout<<n<<endl;
	       		return 0;
			   }
			   else{
			   	cout<<m*2;
			   }
		   }
			else{
				if(m>=(n/2)&&m-(n/2)<2){
					cout<<n-1<<endl;
					return 0;
				}
				else if(m<(n/2)){
					cout<<m*2<<endl;
					return 0;
				}
				else{
					cout<<n<<endl;
					return 0;
				}
		}
	}
}
    for(int i=1;i<=n;i++){
	   if(a[i]<0){
			a[i]=0-a[i];
		} 
		sum[i]=sum[i-1]+a[i];
		if(sum[i]>=m){
			flag=1;
			printf("%d",i);
			return 0;
		}
    }
    printf("%d",n);
	

	return 0;
}
