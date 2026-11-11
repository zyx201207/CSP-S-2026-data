#include <iostream>
using namespace std;
int main(){
    int a[200009],n;
	long long sum=0,cache,cache1,ans=0;
	char b[200009];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin >> a[i]>>b[i];
		sum+=a[i];
	}
	if(sum%2==0) cache=sum/2;
	else cache=sum/2+1;
	cache1=cache;
	int j=1;
	while(cache>a[j]){
		cache-=a[j];
		j++;
	}
	a[j]-=cache;
	int b1=a[1],b2=a[j],b3=1,b4=j;
	while(cache1>0){
		b1--;
		b2--;
		if(b[b3]!=b[b4]) ans++;
		if(b1==0){
			b1=a[b3+1]; 
			b3++;
	    }
	    if(b2==0){
			b2=a[b4+1]; 
			b4++;
	    }
		cache1--;
	}
    if(sum%2==1) ans=ans-1;
	cout << ans;
    return 0;
}


