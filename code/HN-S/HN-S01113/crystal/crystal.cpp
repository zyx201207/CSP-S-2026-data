#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

const int MAX_man=5e5+5;

long long int many;
long long int deal;
long long int each[MAX_man];
long long int pera[MAX_man];
long long int eans[MAX_man];
long long int fans;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>many;
	cin>>deal;
	for(long long int i=1;i<=many;i++){
		cin>>each[i];
		pera[i]=pera[i-1]+each[i];
	}
	
	sort(each+1,each+1+many);
	
	for(long long int end=1;end<=many;end++){
		
		long long int lef=1;
		long long int rig=end-1;
		int cnt=0;
		while(lef<rig){
			cnt++;
			if(cnt>=10)
				break;
			long long int mid=(lef+rig)/2;
			
			long long int need=each[end]*(end-mid)-(pera[end-1]-pera[mid-1]);
			
			if(need>deal)
				lef=mid+1;
			else if(need<deal)
				rig=mid-1;
		}
		long long int mid=(lef+rig)/2;
		//cout<<mid<<endl;
		eans[end]=(end-mid)+1;
	}
	
	for(long long int i=1;i<=many;i++){
		//cout<<eans[i]<<" ";
		fans=max(fans,eans[i]);
	}
	
	cout<<fans;
	return 0;
}
