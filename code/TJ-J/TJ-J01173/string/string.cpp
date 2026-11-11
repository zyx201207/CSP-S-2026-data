#include<bits/stdc++.h>
using namespace std;
long long a[3000000];
long long c[3000000];
string b[3000000];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=a[i];
	}
	long long x=1;
	long long y=n;
	long long sum=0;
	while(x<y){
		if(c[x]==c[y]&&b[x]==b[y]){
			x++,y--;
		}
		else if(c[x]==c[y]&&b[x]!=b[y]){
			sum+=c[y];
			if(b[x]==b[x+1]){
				b[y]=b[x];
			}
			else if(b[y]==b[y-1]){
				b[x]=b[y];
			}
			
			x++;
			y--;
			if(x==y){
				cout<<sum;
				return 0;
			}
			//cout<<"d "<<sum<<endl;
				
		}
		else if(c[x]<c[y]&&b[x]==b[y]){
			c[y]=c[y]-c[x];
			x++;
			if(x==y){
				cout<<sum;
				return 0;
			}
		}
		else if(c[x]>c[y]&&b[x]==b[y]){
			c[x]=c[x]-c[y];
			y--;
			if(x==y){
				cout<<sum;
				return 0;
			}
		}
		else if(c[x]<c[y]&&b[x]!=b[y]){
			c[y]=c[y]-c[x];
			sum+=c[x];
			x++;
			if(x==y){
				cout<<sum;
				return 0;
			}
	
		}
		else if(c[x]>c[y]&&b[x]!=b[y]){
			c[x]=c[x]-c[y];
			sum+=c[y];
			y--;
			if(x==y){
				cout<<sum;
				return 0;
			}
			
		}
		else{
			x++,y--;
		}
	}
	cout<<sum;
	return 0;
}
