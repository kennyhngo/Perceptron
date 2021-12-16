#include <iostream>
#include <vector>
using namespace std;

int dot(vector<int> &a, vector<int> &b)
{
	int sum = 0;
	for (size_t i = 0; i < a.size(); ++i)
	{
		sum += a[i] * b[i];
	}
	return sum;
}

vector<int> add(vector<int> &theta, int y, vector<int> &x)
{
	for (size_t i = 0; i < theta.size(); ++i)
	{
		theta[i] = theta[i] + y * x[i];
	}
	return theta;
}

int main()
{
	vector<int> x1;
	x1.push_back(1);
	x1.push_back(2);

	vector<int> x2;
	x2.push_back(1);
	x2.push_back(0);

	vector<int> x3;
	x3.push_back(-3);
	x3.push_back(2);

	vector<int> y;
	y.push_back(1);
	y.push_back(1);
	y.push_back(-1);

	vector<vector<int> > x;
	x.push_back(x1);
	x.push_back(x2);
	x.push_back(x3);

	// misclassified point = mcp
	bool mcp = false;
	int k = 0;
	vector<int> theta;
	theta.push_back(0);
	theta.push_back(0);

	while (!mcp)
	{
		mcp = true;
		for (size_t i = 0; i < 3; ++i)
		{
			cout << theta[0] << " " << theta[1] << endl;
			if (y[i] * dot(theta, x[i]) <= 0)
			{
				theta = add(theta, y[i], x[i]);
				++k;
				mcp = false;
			}
		}
	}
	cout << k << endl;
	return 0;
}