#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005];

long long total=0,ans=0;
bool str_hw(int i){
	char l,r;
	int tmp=i,x1=0,x2=0; 
	while(tmp<0){
		
		tmp-=a[x1];
		x1++;
	}
	l=c[x1];
	tmp=total+1-i;
	while(tmp<0){
		
		tmp-=a[x2];
		x2++;
	}
	r=c[x2];
	
	if(c[x1]==c[x2])return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		total+=a[i];
	}
	for(int i=0;i<total/2;i++)
	{
		if(str_hw(i)){
			ans++;
			
		}
		
	}
	cout<<ans;
	return 0;
}

