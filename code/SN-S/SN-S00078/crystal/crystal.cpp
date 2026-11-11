#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long min1=1<<31-1,min_,n,m,h=0;
	int a[50001];
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i],h+=a[i];
	h/=n;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int c=abs(h-a[i]);
		if(c<min1) min1=c,min_=i;
	}
	int k=0,men=0;
	while(m>0){
		int nb=abs(a[min_]-a[k++]);
		a[k]+=nb;
		m-=nb;
	}
	for(int i=0;i<n;i++)
		if(a[i]==a[min_]) men++;
	cout<<men;
}
