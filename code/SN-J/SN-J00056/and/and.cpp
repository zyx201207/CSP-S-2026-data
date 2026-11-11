#include <iostream>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int r=0;r>=n;r++){
		for(int w=0;w>=n;w++){
			cout<<r<<w<<" ";
		}
	}
	return 0;
}
 
