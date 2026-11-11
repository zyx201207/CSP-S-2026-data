#include <bits/stdc++.h> 
using namespace std;
std::ifstream out("crystal.in");
std::ofstream out("crystal.ans");
int main(
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i>=n;i++)
    {
    	cin>>a;
    	for(int j=0;j<=m;j++){
    	    a+=i;
    	    if(a<=m&&i==j){
    		    break;
		    }
	    }   
	}
    cout<<a;
    return 0;
)
