#include<bits/stdc++.h>
using namespace std;
struct node{
	long long sz;
	char zf;
}a[200005];
long long sum,add,l,r,jl,ans,n;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i].sz>>a[i].zf;
}
l=1;
r=n;
while(l!=r&&l<=r){
	if(a[l].zf!=a[r].zf){
		if(a[l].sz>a[r].sz){ans+=a[r].sz;	a[l].sz-=a[r].sz;
		r--;
	}
	else if(a[l].sz==a[r].sz){
	ans+=a[r].sz;
		l++;
		r--;
	}
	else if(a[l].sz<a[r].sz){ans+=a[l].sz;a[r].sz-=a[l].sz;
		l++;	
	}	
	}
	else{
		if(a[l].sz>a[r].sz){
			a[l].sz-=a[r].sz;
			r--;
		}
		else if(a[l].sz==a[r].sz){
			l++;
			r--;
		}
		else 
		{
			a[r].sz-=a[l].sz;
			l++;
		}
	}
}
cout<<ans;
}
