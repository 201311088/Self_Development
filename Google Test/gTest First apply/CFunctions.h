class CFunctions {
public:
   	CFunctions();
	CFunctions(int num_of_index);

	int Insert(int value);
	void Delete(int index);
	void Update(int index, int value);
	int Search(int index);

	int getValue(int index);
	int getIndex();

private:
	int m_nArr[100];
	int m_nIndex_pointer;
};