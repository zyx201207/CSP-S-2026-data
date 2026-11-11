#include <fstream>
#include <algorithm>
#include <vector>
#define maxn 263599
using namespace std;
int n,m;
int a[maxn];
vector<int> mp[32];
ifstream fin("and.in");
ofstream fout("and.out");
int fastpow(int x,int y){
	int ans=1,base=x;
	while(y>0){
		if(y&1) (ans*=base);
		base=base*base;
		y/=2;
	}
	return ans;
}
int count2(int target){
	return fastpow(2,target+1)-1;
}
int count(int target){
	vector<int> mp2635[32];
	for(auto e:mp[target]){
		int i=30,pow=fastpow(2,30);
		int temp=e;
		while(temp>0){
			if(temp>=pow){
				temp-=pow;
				mp2635[i].push_back(e);
			}
			i--;
			pow/=2;
		}
	}
	int temp=count2(target);
	int minus=0;
	for(int i=target;i>=0;i--){
		if((int)mp2635[i].size()<m){
			minus+=fastpow(2,i);
		}
	}
	return temp-minus;
}
int main() {
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
		int j=30,pow=fastpow(2,30);
		int temp=a[i];
		while(temp>0){
			if(temp>=pow){
				temp-=pow;
				mp[j].push_back(a[i]);
			}
			j--;
			pow/=2;
		}
	}
	for(int i=30;i>=0;i--){
		if((int)mp[i].size()>=m){
			fout<<count(i)<<endl;
			return 0;
		}
	}
}