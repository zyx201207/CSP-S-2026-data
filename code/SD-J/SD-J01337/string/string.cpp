#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000];
char b[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int y;
	long long n,sum=0;
	cin>>n;
	for (int i=0;i<n;i++){
		int t;
		char c;
		cin>>t>>c;
		a[i]=t; 
		b[i]=c;
	}
    for (int i=0;i<n-1;i++){
    	if (a[i]==a[i+1]) y=1;
	}
	if (y==1){
		for (int i=0,j=0;i<n/2;i++,j++){
		    if (b[i]==b[n-j-1]){
			    continue;
		    } 
		    else sum+=a[0];
	    }
	}
	else {
		for (int i=0;i<n;i++){
			int r=a[i];
			char e=b[i];
			for(int i=0;i<a[i];i++) s+=b[i];
		}
	}
	//0µ½n-1;
	for (int i=0,j=0;i<n-1;i++,j++){
		if (s[i]==s[n-j-1]){
			continue;
		} 
		else sum++;
	}
	cout<<sum;
	return 0;
}
