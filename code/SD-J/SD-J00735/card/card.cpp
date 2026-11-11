#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a[N+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n<<endl;
	}
	else if(m==2){
		int q1=0,q2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)q1++;
			else q2++;
		}
		if(a[n]==1){
			cout<<n<<" "<<q2<<endl;
		}
		else{
			cout<<q1<<" "<<n<<endl;
		} 
	}
	return 0;
} 
