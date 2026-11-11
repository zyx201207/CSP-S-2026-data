#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
	int cnt;
	string c;
}a[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	bool f=1;
	cin>>n;
	int j=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		b[j].cnt=a[i].cnt;
		b[j].c=a[i].c;
		j--;
		sum+=a[i].cnt;
	}
	for(int i=1;i<n;i++){
		if(a[i].cnt!=a[i+1].cnt){
			f=0;
		}
	}
	if(!f){
			long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i].c!=b[i].c){
				sum=sum+abs(a[i].cnt-b[i].cnt);
			}
		}
		cout<<sum;
	}
	else{
		int idex=ceil(1.0*n/2);
		if(n%2==1){
			sum=sum-a[idex].cnt;
		}
		if(n%2==0)sum/=2; 
		cout<<sum;
	}
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Node{
	int c;
	string s;
}a[N];
int main(){
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].s;
		sum+=a[i].c;
	}
	int idex=ceil(1.0*n/2);
	if(n%2==1){
		sum=sum-a[idex].c;
	}
	if(n%2==0)sum/=2; 
	cout<<sum;
	return 0;
}
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b */
