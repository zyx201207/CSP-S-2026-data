#include<bits/stdc++.h>
using namespace std;
long long n,x,y;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		y+=a[i];
	}
	x=0;
	long long sum=0,s1=0,s2=n-1;
	long long t=0;
	while(x<y){
		if(b[s1]!=b[s2]){
			if(a[s1]<a[s2]){
				t=a[s1];
				sum+=a[s1];
				a[s2]-=a[s1];
				a[s1]=0;
			}else{
				t=a[s2];
				sum+=a[s2];
				a[s1]-=a[s2];
				a[s2]=0;
			}
		}else{
			t=min(a[s1],a[s2]);
			a[s1]-=t;
			a[s2]-=t;
		}
		x+=t;
		y-=t;
		if(a[s1]<=0){
			s1++;
		}
		if(a[s2]<=0){
			s2--;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
