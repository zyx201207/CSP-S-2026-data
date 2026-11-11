#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,sum=0;
	cin>>n;
	int head=1,tail=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	while(head<tail){
		if(c[head]!=c[tail]){
			sum+=min(a[head],a[tail]);
		}
		if(a[head]>a[tail]){
			a[head]-=a[tail];
			tail--;
		}
		else if(a[head]<a[tail]){
			a[tail]-=a[head];
			head++;
		}
		else{
			tail--;head++;
		}
	}
	cout<<sum;
	return 0;
}