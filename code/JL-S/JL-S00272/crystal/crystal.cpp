#include<bits/stdc++.h>
using namespace std;
long long line[10000001];
long long line1[10000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,max=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>line[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(line[j]<line[i]){
				long long t=line[i];
				line[i]=line[j];
				line[j]=t;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		long long q=m;
		long long a=1;
		for(long long j=1;j<=i;j++){
			line1[a]=line[i]-line[j];
		//	cout<<line[i]<<" "<<line[j]<<endl;
			a++;
		}
		for(long long j=1;j<=a-1;j++){
			for(long long y=j;y<=a-1;y++){
				if(line1[y]<line1[j]){
					long long t=line1[j];
					line1[j]=line1[y];
					line1[y]=t;
				}
			}
		}
		long long cnt=0;
		
		for(long long j=1;j<=a-1;j++){
			
			q-=line1[j];
			cnt++;
			if(q<line1[j+1]){
				break;
			}
		}
		if(cnt>max){
			max=cnt;
		}
	}
	cout<<max;
	
	return 0;

}
