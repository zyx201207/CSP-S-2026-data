#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
int32_t maxi(const std::vector<int32_t>& arr){
	int32_t ma = -1e9;
	for(int32_t i:arr){
		if(ma<i)
			ma=i;
	}
	return ma;
}
int32_t ma=-1e9;
void ds(std::vector<bool>& yes,const std::vector<int32_t>& arr,int32_t used,const int32_t goal,int32_t now){
	if(used==goal){
		if(ma<now)
			ma=now;
		return;
	}
	for(size_t i=0;i<arr.size();i++){
		if(yes[i])
			continue;
		yes[i]=true;
		ds(yes,arr,used+1,goal,now&arr[i]);
		yes[i]=false;
	}
}
int32_t l2(int32_t num){
	int32_t ans=0;
	while(num>>ans)
		ans++;
	return ans;
}
bool al(const std::vector<int32_t>& s){
	for(int32_t i:s){
		if(i!=(1<<(l2(i)+1))-1)
			return false;
	}
	return true;
}
bool sl(const std::vector<int32_t>& s){
	if((int32_t)s.size()!=(1<<(l2(s.size()))))
		return false;
	for(size_t i=0;i<s.size();i++)
		if(s[i]!=(int32_t)i)
			return false;
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int32_t n,m;
	scanf("%d %d",&n,&m);
	std::vector<int32_t> arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	if(m==1){
		printf("%d\n",maxi(arr));
		return 0;
	}
	if(m==n){
		int32_t ans=0xffffffff;
		for(int32_t i:arr)
			ans&=i;
		printf("%d\n",ans);
		return 0;
	}
	if(m==n-1){
		int32_t mai=-1e9;
		for(int i=0;i<n;i++){
			int32_t ans=0xffffffff;
			for(int j=0;j<n&&j!=i;j++)
				ans&=arr[j];
			if(ans>mai)
				mai=ans;
		}
		printf("%d\n",mai);
		return 0;
	}
	if(al(arr)){
		printf("%d\n",maxi(arr));
		return 0;
	}
	if(sl(arr)){
		int32_t ans=0xffffffff;
		for(int i=n-1;i>=n-m;i--)
			ans&=arr[i];
		printf("%d\n",ans);
		return 0;
	}
	std::vector<bool> sign(n,0);
	ds(sign,arr,0,m,0xffffffff);
	printf("%d\n",ma);
	return 0;
}