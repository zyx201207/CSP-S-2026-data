#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
class stack{
private:
	int32_t *bsp=nullptr,*rsp=nullptr;
public:
	void push(int32_t val){
		*rsp=val,rsp++;
	}
	void pop(){
		rsp--;
	}
	int32_t get(){
		return *(rsp-1);
	}
	stack(int32_t size){
		bsp = new int32_t[size+1];
		rsp=bsp;
	}
	~stack(){
		delete bsp;
		bsp=nullptr,rsp=nullptr;
	}
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int32_t n,m;
	scanf("%d %d ",&n,&m);
	std::vector<int32_t>arr(n);
	for(int32_t& i:arr)
		scanf("%d",&i);
	std::reverse(arr.begin(),arr.end());
	std::vector<int32_t>hv(m+1,-1);
	std::vector<int32_t>dhv(m+1,0);
	stack st(n);
	int32_t now=0;
	for(int i=0;i<n;i++){
		st.push(arr[i]);
		if(hv[arr[i]]!=-1){
			for(int i=0;i<=i-hv[arr[i]];i++){
				hv[arr[st.get()]]=-1;
				st.pop();
				now--;
			}
		}
		else
		for(int i=0;i<m;i++)
			dhv[arr[i]]+=hv[arr[i]]!=-1;
		now++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",dhv[i]);
	putchar(10);
}