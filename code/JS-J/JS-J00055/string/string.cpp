#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> num;
vector<char> ch;
long long res;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	num.resize(n);
	ch.resize(n);
	long long sum=0;
	for(int i=0;i<n;++i){
		cin>>num[i]>>ch[i];
		sum+=num[i];
	}
	int left=0;
	int Ls=num[left];
	int right=n-1;
	int Rs=num[right];
	while(left<right){
		int low=min(Ls,Rs);
		if(ch[left] != ch[right]) res+=low;
		Ls-=low;
		Rs-=low;
		if(Ls==0){
			left++;
			Ls=num[left];
		}
		if(Rs==0){
			right--;
			Rs=num[right];
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
