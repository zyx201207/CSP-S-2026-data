#include<iostream>
using namespace std;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ci=0,co,ans=0,vi=0,vo=0;
    bool qi;
    cin>>n;
    co=n-1;
    int nn[n+5];
    char n2[n+5];
    for(int i=0;i<n;i++){//input2
    	cin>>nn[i]>>n2[i];
	}
	while(ci<=co){
		ans=min(nn[ci]-vi,nn[co]-vo);
		if(n2[ci]!=n2[co]){//count
			cnt+=ans;
		}
		if(nn[ci]-vi>nn[co]-vo){//change
			vi+=ans;
			vo=0;
			co--;
		}else{
			vo+=ans;
			vi=0;
			ci++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

