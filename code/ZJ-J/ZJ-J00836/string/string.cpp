#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int num;
	char c;
};
node a[200100];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num >>a[i].c ;
		sum+=a[i].num ;
	}
	int l=1,r=n;
	long long ll=0,rr=sum+1;
	long long ans=0;
	while(l<r){
		if(a[l].c ==a[r].c ){
			if(a[l].num <a[r].num ){
				ll+=a[l].num ,rr-=a[l].num ;
				a[r].num -=a[l].num ;
				l++;
			}
			else if(a[l].num >a[r].num ){
				ll+=a[r].num ,rr-=a[r].num ;
				a[l].num -=a[r].num ;
				r--;
			}
			else if(a[l].num ==a[r].num ){
				ll+=a[l].num ,rr+=a[r].num ;
				l++,r--;
			}
		}
		else if(a[l].c !=a[r].c ){
			if(a[l].num <a[r].num ){
				ll+=a[l].num ,rr-=a[l].num ;
				a[r].num -=a[l].num ;
				ans+=a[l].num ;
				l++;
			}
			else if(a[l].num >a[r].num ){
				ll+=a[r].num ,rr-=a[r].num ;
				a[l].num -=a[r].num ;
				ans+=a[r].num ;
				r--;
			}
			else if(a[l].num ==a[r].num ){
				ll+=a[l].num ,rr+=a[r].num ;
				ans+=a[l].num ;
				l++,r--;
				
			}
		}
	}
	cout<<ans;
	return 0;
}

