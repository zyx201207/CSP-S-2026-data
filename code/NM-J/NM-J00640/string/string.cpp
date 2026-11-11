#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct s{
	int d;
	char a;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<s>vec;
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		s slm;
		cin>>slm.d>>slm.a;
		vec.push_back(slm);
	}
	int right=vec.size()-1;
	int left=0;
	long long fl=0;
	while(right>left){
		if(vec[left].a==vec[right].a){
			if(vec[left].d>vec[right].d){
				vec[left].d-=vec[right].d;
				right--;
			}else{
				vec[right].d-=vec[left].d;
				left++;
			}
		}else{
			if(vec[left].d>vec[right].d){
				fl+=vec[right].d;
				vec[left].d-=vec[right].d;
				right--;
				
			}else{
				fl+=vec[left].d;
				vec[right].d-=vec[left].d;
				left++;
			}
		}
	}
	cout<<fl;
	return 0;
} 
