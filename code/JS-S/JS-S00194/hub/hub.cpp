#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <list>
#include <functional>
using namespace std;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	for(int i = 1; i <= b; i++){
		cout << i << endl;
	}//That's all I can write about
	//I don't know how to type in Chinese, so I have to do this
	//Now, I need to get 888 bytes for all the four tasks, so I want to write an essay here
	//My essay below is about a new kind of maths
	//Why is maths based on equations? Can't we derive formulae with inequality?
	//Now I have an inequality a != b
	//It's manifest that a + c != b + c
	//However, we cannot have a * c != b * c, because c can be 0 or infinity(If we don't consider the sign of the infinity)
	//infinity is only a theoretic value, and we cannot truly reach it
	//what about zero? is it a value that we cannot reach?
	//it is wrong, obviously. If a temperature rise by t degree Kelvin, and then drop by t degree Kelvin, the net change in temperature is 0 Kelvin
	//So we can define 0 as n-n, it can be reached
	//Oops, I wrote for more than 888 bytes, so I will try to get 1888 or 2888
	//However, this is in addition, what about multiplication?
	//We have F = ma, if the net acceleration of a object is 0, its resultant force will also be zero
	//So being multiplicated by 0 really matters
	//But for times 0 as a scale, its unreachable
	//this can be get from the graph of y=1/x
	//We need to distinguish these two multiplications, so I define multiplication1(An easy way to calculate addition) and multiplication2(Being multiplicated as a scale) (Here are some logical issues, F=Ma seems not to be an addition, but its Okay here)
	//Zero in multiplication2 is unreachable, so we can let the operation of being multiplicated by 0 be illegal
	//As a result, we now have a * c != b *c (For multiplication2)
	//Additionally, two multiplication axes can be drawn, one of them has one end of 0, one end of positive infinity, and the middle of it is 1
	//Another one has one end of -0, one end of negative infinity, and the middle of it is -1
	//So what about being multiplicated by a negative value? We don't discuss it here
	//However, there's another way to let an inequality become an equality
	//That's for a != -a (a belongs to R), take a even-number power, or take the absolute value
	//We have enough basis before to soleve this problem(How to make an inequality never become an equality if we take the same options on both sides), so readers should prove it individually
	//A splendid way of proving has just come to me, but there's not enough space here
	//So I have to stop here, Thanks for your reading. Bythe way, trick or treats!
	return 0;
}
