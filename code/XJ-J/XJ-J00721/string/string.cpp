# include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	string s[n];
	int a[n];
	int j=n-1,i=0;
	for(int x=0;x<n;x++){
		cin>>a[x]>>s[x];
	}
	if(n%2==0) n=n;
	else n--;
	while(i<n/2){
	if(s[i]!=s[j]){
			if(a[i]>a[j]){
	   	cnt+=a[j];
	   	a[i]=a[i]-a[j];
	   	j--;
	   }
	      if(a[j]>a[i]){
	   	cnt+=a[i];
	   	a[j]=a[j]-a[i];
	   	i++;
	   }
	   if(a[i]==a[j]){
	   	cnt+=a[i];
		i++;
	   	j--;
	   }
	}
	else if(s[i]==s[j]){
		if(a[i]>a[j]){
	   	a[i]=a[i]-a[j];
	   	j--;
	   }
	    if(a[j]>a[i]){
	   	a[j]=a[j]-a[i];
	   	i++;
	   }
	   if(a[i]==a[j]){
	   	i++;
	   	j--;
	   }
	}
}
	cout<<cnt;
	return 0 ;
}