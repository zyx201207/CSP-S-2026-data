#include<bits/stdc++.h>
using namespace std;



struct hello {
	char character; int amt;
}fwfwfwfw[2000005];




long long differences = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	
	cin>>n;


	long long left = 1;
	for (int i =1 ;i<= n;i ++) {
		cin>> fwfwfwfw[i].amt;

		left+=fwfwfwfw[i].amt;
		cin>>fwfwfwfw[i].character;
	}
	
	//for (int i =1; i<= left; i++) cout<<getcharat(i,n)<<'\n';
	
	differences = 0;
	
	char leftChar, rightChar; long long leftRemains = 0, rightRemains = 0;
	int lID = 1, rID = n;
	long long compared = 0;
	while (compared < left) {
		if (leftRemains == 0) {
			leftChar = fwfwfwfw[lID].character;
			leftRemains = fwfwfwfw[lID].amt;
			lID++;
		}
		if (rightRemains == 0) {
			rightChar = fwfwfwfw[rID].character;
			rightRemains = fwfwfwfw[rID].amt;
			rID--;
		}
		if (leftChar != rightChar) {
			long long modifies =min(leftRemains, rightRemains);
			differences += modifies;
			leftRemains -= modifies, rightRemains -= modifies;
			compared += modifies;
			
		}
		if (leftChar == rightChar) {
			long long modifies = min(leftRemains, rightRemains);
			leftRemains -= modifies, rightRemains -= modifies;
			compared += modifies;
		}
	}
	
	cout<<differences/2;
	

	return 0;
	
	

	return 0;
}
