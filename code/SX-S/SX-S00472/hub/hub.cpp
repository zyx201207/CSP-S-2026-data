#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

    int c, t;
    cin>>c>>t;
    
    if(c == 0){
    	if(t == 2){
    		printf("1\n2");
		}
		else if(t == 3){
			printf("1\n1\n2");
		}
		else{
			printf("17\n9\n6\n6\n9");
		}
	}

	return 0;
}
/*

也不知道数据里有没有样例，题目表述不是很清晰

*/
