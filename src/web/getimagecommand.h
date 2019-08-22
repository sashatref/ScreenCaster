#ifndef GETIMAGECOMMAND_H
#define GETIMAGECOMMAND_H


class GetImageCommand : public ICommandHandler
{
public:
    GetImageCommand()
    {

    }

    // ICommandHandler interface
public:
    virtual void execute(QByteArray &_data, QByteArray &_contentType) override;
    virtual QStringList allowedMethod() const override;
};

#endif // GETIMAGECOMMAND_H
