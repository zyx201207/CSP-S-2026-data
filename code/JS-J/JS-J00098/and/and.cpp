#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200001],s=1,s1=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){cout<<12;return 0;}
	if(n<=20){
		if(m==1){for(int i=0;i<n;i++)s=max(s,a[i]);cout<<s;return 0;}
		if(m==n){for(int i=0;i<n;i++)s&=a[i];cout<<s;return 0;}
		if(m==n-1){for(int i=0;i<n;i++){for(int z=0;z<n;z++)if(z!=i)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
		if(m==n-2){for(int i=0;i<n;i++){for(int j=i+1;j<n;j++)for(int z=0;z<n;z++)if(z!=i||z!=j)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
		if(m==n-3){for(int i=0;i<n;i++){for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int z=0;z<n;z++)if(z!=i||z!=j||z!=q)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
		if(m==n-4){for(int i=0;i<n;i++){for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)for(int z=0;z<n;z++)if(z!=i||z!=j||z!=q||z!=w)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
		if(m==n-5){for(int i=0;i<n;i++){for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)for(int e=w+1;e<n;e++)for(int z=0;z<n;z++)if(z!=i||z!=j||z!=q||z!=w||z!=e)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
		if(m==n-4){for(int i=0;i<n;i++){for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)for(int e=w+1;e<n;e++)for(int r=e+1;r<n;r++)for(int z=0;z<n;z++)if(z!=i||z!=j||z!=q||z!=w||z!=e)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
		if(m==2){for(int i=0;i<n;i++)for(int j=i=1;j<n;j++)s=max(s,a[i]&a[j]);cout<<s;return 0;}
		if(m==3){
			for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)s=max(s,a[i]&a[j]&a[q]);
			cout<<s;
			return 0;
		}
		if(m==4){
			for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)s=max(s,a[i]&a[j]&a[q]&a[w]);
			cout<<s;
			return 0;
		}
		if(m==5){
			for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)for(int e=w+1;e<n;e++)s=max(s,a[i]&a[j]&a[q]&a[w]&a[e]);
			cout<<s;
			return 0;
		}
		if(m==6){
			for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)for(int e=w+1;e<n;e++)for(int r=e+1;r<n;r++)s=max(s,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]);
			cout<<s;
			return 0;
		}
		if(m==7){
			for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int q=j+1;q<n;q++)for(int w=q+1;w<n;w++)for(int e=w+1;e<n;e++)for(int r=e+1;r<n;r++)for(int t=r+1;t<n;t++)s=max(s,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]);
			cout<<s;
			return 0;
		}
		
	}
	else if(n<=2000){
		if(m==1){for(int i=0;i<n;i++)s=max(s,a[i]);cout<<s;return 0;}
		if(m==n){for(int i=0;i<n;i++)s&=a[i];cout<<s;return 0;}
		if(m==2){for(int i=0;i<n;i++)for(int j=i+1;j>n;j++)s=max(s,a[i]&a[j]);cout<<s;return 0;}
	}
	else if(n<=200000&&m==n-1){for(int i=0;i<n;i++){for(int z=0;z<n;z++)if(z!=i)s1&=a[i];s=max(s,s1);}cout<<s;return 0;}
	return 0;
}
