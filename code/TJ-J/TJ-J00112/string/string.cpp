#include <cstdio>
#include <cstdint>
#include <vector>
struct p{
	int32_t length=0;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int32_t n;
	scanf("%d",&n);
	std::vector<p>arr(n+1);
	for(int i=1;i<=n;i++){
		scanf(" %d %c",&(arr.at(i).length),&(arr.at(i).c));
		arr.at(i).length+=arr.at(i-1).length;
	}
	std::vector<char> a(n+1);
	auto s=arr.begin()+1;
	for(int i=0;i<arr[n].length/2;i++){
		sign:
		if(i<=s->length)
			a[i]=s->c;
		else{
			s++;
			goto sign;
		}
	}
	int32_t ans=0;
	for(int i=0;i<arr[n].length/2-1;i++){
		if(a[i]!=a[arr[n].length-i-1])
			ans++;
	}
	printf("%d\n",ans);
}